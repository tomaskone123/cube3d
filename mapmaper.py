# generate_large_cub.py
import random

size = 1000
filename = "huge_test_1000x1000.cub"

# Player start near center
player_pos = (size // 2, size // 2)

with open(filename, "w") as f:
    # Write textures and colors
    f.write("NO ./textures/north.xpm\n")
    f.write("SO ./textures/south.xpm\n")
    f.write("WE ./textures/west.xpm\n")
    f.write("EA ./textures/east.xpm\n")
    f.write("F 100,100,100\n")
    f.write("C 200,200,200\n")

    for y in range(size):
        row = ""
        for x in range(size):
            # Edges are walls
            if x == 0 or x == size-1 or y == 0 or y == size-1:
                row += "1"
            # Place player
            elif (y, x) == player_pos:
                row += "N"
            # Random interior walls (~5% chance)
            elif random.random() < 0.05:
                row += "1"
            else:
                row += "0"
        f.write(row + "\n")

print(f"{filename} generated successfully!")
