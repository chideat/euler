from __future__ import division

def plot(filename, t):
    import pygame
    import pygame.gfxdraw

    scale = 8
    size = scale * len(t)
    w, h = size, size

    s = pygame.Surface((w, h))

    max_c = max([max(r) for r in t])

    for y in range(len(t)):
        for x in range(y + 1):
            Y = scale // 2 + y * scale
            X = w // 2 + scale // 4 + x * scale - Y // 2
            r = int(scale / 2.3)
            c = int(255 * t[y][x] / max_c)

            pygame.gfxdraw.filled_circle(s, X, Y, r, (c, c, c))

    pygame.image.save(s, filename)

def solve(t):
    for y in range(len(t) - 2, -1, -1):
        for x in range(y + 1):
            l = t[y + 1][x]
            r = t[y + 1][x + 1]
            t[y][x] += max(l, r)

    return t[0][0]

s = open("67_data").read()
t = [[int(n) for n in l.split()] for l in s.split("\n")[:-1]]

plot("pe067-1-before.png", t)

print solve(t)

plot("pe067-2-after.png", t)
