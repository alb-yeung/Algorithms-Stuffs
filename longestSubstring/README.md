# Longest Substring Without Repeating Characters

From [https://leetcode.com/problems/longest-substring-without-repeating-characters/](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

At first, I thought of a solution to just track where all the characters were, so I could just subtract the places to get the length between two repeated characters, but that became an issue because I couldn't think of how to combine it with cases where the longest substring contained the first or last letter. After some thinking, I transitioned my solution into going through normally, and instead marking only where repeated characters are found, and working from there.

For a string of "abdcaceeeeefcabg", my code will do the following

Variable | Value
---      | ---
Max      | 0
lastReset| -1

Key | Value
--- | ---
a   | -1
b   | -1
c   | -1
d   | -1
e   | -1
f   | -1
g   | -1

Will be what it looks like at the start after setup. In the main loop of the function, when a is reached, this is what happens.

When i == 0

Variable | Value
---      | ---
Max      | 1
lastReset| -1

Key | Value
--- | ---
a   | 0
b   | -1
c   | -1
d   | -1
e   | -1
f   | -1
g   | -1

The algorithm keeps track of where 'a' was last seen, and because 'a' hasn't been seen before, lastReset isn't changed but Max is.

When i == 1

Upon seeing 'b',

Variable | Value
---      | ---
Max      | 2
lastReset| -1

Key | Value
--- | ---
a   | 0
b   | 1
c   | -1
d   | -1
e   | -1
f   | -1
g   | -1

The same thing occurs as for 'a' but the Max and Value for 'b' is different. The same thing happens for 'd' and 'c'. However, when an 'a' is reached again, something different happens.

When i == 4

Variable | Value
---      | ---
Max      | 4
lastReset| 1

Key | Value
--- | ---
a   | 4
b   | 1
c   | 3
d   | 2
e   | -1
f   | -1
g   | -1

It sees that 'a' has been found in the string previously, and then calculates what the previous substring has been, in this case, 4. It then sets `lastReset` to right in front of where 'a' has just been found, in this case, 1 because 'a' was at 0 previously. Finally, it sets 'a''s value in the map to its current spot, 4.

On the next letter, the same happens for 'c'. It calculates the length of the previous substring, and sets lastReset to in front of where the previous 'c' was found.

When i == 5

Variable | Value
---      | ---
Max      | 4
lastReset| 4

Key | Value
--- | ---
a   | 4
b   | 1
c   | 5
d   | 2
e   | -1
f   | -1
g   | -1

This runs until the very end, and the final variables would look like 

When i == 16

Variable | Value
---      | ---
Max      | 5
lastReset| 10

Key | Value
--- | ---
a   | 13
b   | 14
c   | 12
d   | 2
e   | 10
f   | 11
g   | 15

I included a special calculation at the end of the string to calculate if the longest substring contains the last character. In this case, `i` would go one past the length of s, and then subtract from the lastReset. It would get 6 and would return 6 as that would be the max.