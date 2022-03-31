import sys

import pygame

from settings import Settings

def run_game():
    """init game/create a screen object"""
    pygame.init()

    gm_settings = Settings()
    # set screen size
    screen = pygame.display.set_mode((gm_settings.screen_w, gm_settings.screen_h))
    pygame.display.set_caption('外星人大作战')

    bg_color = (244, 252, 217)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

        screen.fill(gm_settings.bg_color)

        pygame.display.flip()

run_game()
