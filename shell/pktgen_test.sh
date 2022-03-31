#!/bin/bash

function usage() {
	echo ""
	echo "Usage: $0 -i ethX"
	echo "  -i : (\$DEV)  output interface/device(required)"
	echo "  -s : (\$PKT_SIZE) packet size"
	echo "  -d : (\$DEST_IP) destionation ip"
	echo "  -m : (\$DEST_MAC) destionation mac"
	echo "  -t : (\$THREADS)  number of threads(default 1)"

	exit 0
}

function pg_cmd() {
	local result
	local proc_file=$1
	local status=0

	#after shift, remaining args are contained in $@
	shift
	local proc_ctrl=${PROC_DIR}/$proc_file
	
	if [ ! -e "$proc_ctrl" ]; then
	    echo "ERROR: $proc_ctrl doesnot exists"
		exit 1
	fi

	echo "cmd: $@ > $proc_ctrl"
	echo "$@" > "$proc_ctrl" || status=$?

	if [[ "$proc_file" != "pgctrl" ]]; then
	    result=$(grep "Result: OK:" $proc_ctrl) || true
		if [[ "$result" == "" ]]; then
		    grep "Result:" $proc_ctrl >&2
		fi
	fi

	if (( $status != 0)); then
	    echo "ERROR: write error($(status)) occured cmd: \"$@ > $proc_ctrl\""
	fi
}

function pg_thread() {
	local thread=$1
	local proc_file="kpktgend_${thread}"
	shift
	pg_cmd ${proc_file} "$@"
}

function pg_ctrl() {
	local proc_file="pgctrl"
	pg_cmd ${proc_file} "$@"
}

function pg_set() {
	local dev=$1
	local proc_file="$dev"
	shift
	pg_cmd ${proc_file} "$@"
}

function pg_stop() {
	pg_ctrl "stop"
	echo "stop"
}

set -e

DEV=""
PKT_SIZE=1024
DEST_IP=172.20.20.40
DEST_MAC=02:00:00:21:23:2a
THREADS=1

PROC_DIR=/proc/net/pktgen

while getopts "i:s:d:m:t:" opts; do
    case $opts in
	    #iface
		i)
		DEV=$OPTARG
		echo "set device interface to $DEV"
		;;
		# pkt size
		s)
		PKT_SIZE=$OPTARG
		echo "set pkt size to $PKT_SIZE"
		;;
		# destination ip
		d) 
		DEST_IP=$OPTARG
		echo "set dst ip to $DEST_IP"
		;;
		# destination mac
		m) 
		DEST_MAC=$OPTARG
		echo "set dst mac to $DEST_MAC"
		;;
		# number of threads to run
		t) 
		THREADS=$OPTARG
		echo "set number of threads to $THREADS"
		;;
		h|?|*)
		usage
	esac
done
shift $(( $OPTIND - 1 ))

pg_ctrl "reset"
# Config Start Here -------------------------------------
for (( thread = 0; thread < $THREADS; ++thread )); do
	PGDEV=${DEV}@$thread
	echo "Removing all devices"
	pg_thread $thread "rem_device_all"
	echo "Adding eth0"
	pg_thread $thread "add_device $PGDEV"

    # Notice config queue to map to cpu (mirrors smp_processor_id())
    # It is beneficial to map IRQ /proc/irq/*/smp_affinity 1:1 to CPU number
    pg_set $PGDEV "flag QUEUE_MAP_CPU"

	# device config
	CLONE_SKB="clone_skb 000000"
	#PGDEV=/proc/net/pktgen/eth0
	echo "Configuring $PGDEV"
	pg_set $PGDEV "count 10000000"
	pg_set $PGDEV "clone_skb 000000"
	pg_set $PGDEV "pkt_size $PKT_SIZE"
	pg_set $PGDEV "delay 0"
	pg_set $PGDEV "dst $DEST_IP"
	pg_set $PGDEV "dst_mac $DEST_MAC"
done

# Time to run
echo "Running... ctrl^C to stop"
trap pg_stop SIGINT

pg_ctrl "start"
echo "Done"

# Print results
for ((thread = 0; thread < $THREADS; thread++)); do
    dev=${DEV}@${thread}
    echo "Device: $dev"
    cat /proc/net/pktgen/$dev | grep -A2 "Result:"
done
