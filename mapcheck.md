<!--
WSL Compile
cc src/*.c includes/so_long.h lib/libft/*.c lib/libft/*.h
 -->
# Map checklist

Does the map file exist ? ✔

Is the map rectangular ? ✔

All the lines should be the same length. ✔

Is there something in the map file ? ✔

Is the map enclosed in walls ? ✔

Is there only one exit ? ✔

Is there only one start position ? ✔

Is there at least one collectibles ? ✔

#### Subject
The map has to be constructed with 3 components: walls, collectibles, and free
space.
• The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position.

Here is a simple valid map:
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

• You have to check if there’s a valid path in the map.


• Another example of a minimal .ber map:
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
