# ft_ls

Realisation de la commande ls . Vitesse egale a la vrai commande .

![alt tag](https://github.com/pacifistes/ft_ls/blob/master/Screen%20Shot%202017-03-19%20at%208.44.01%20PM.png?raw=true)

| option | description |
| ------------- | - |
| a	 | Include directory entries whose names begin with a dot (.). |
| l	 | (The lowercase letter ``ell''.)  List in long format.  (See below.)  If the output is to a terminal, a total sum for all the file sizes is output on a line before the long listing. |
| r	 | Reverse the order of the sort to get reverse lexicographical order or the oldest entries first (or largest files last, if combined with sort by size |
| R	 | Recursively list subdirectories encountered. |
| t	 | Sort by time modified (most recently modified first) before sorting the operands by lexico-graphical lexicographical graphical order. |
| A	 | List all entries except for . and ...  Always set for the super-user. |
| c	 | Use time when file status was last changed for sorting (-t) or long printing (-l). |
| d	 |  Directories are listed as plain files (not searched recursively). |
| f	 |  Output is not sorted.  This option turns on the -a option. |
| F	 |  Display a slash (`/') immediately after each pathname that is a directory, an asterisk (`*') after each that is executable, an at sign (`@') after each symbolic link, an equals sign (`=') after each socket, a percent sign (`%') after each whiteout, and a vertical bar (`|') after each that is a FIFO. |
| g	 | This option is only available for compatibility with POSIX; it is used to display the group name in the long (-l) format output (the owner name is suppressed). |
| G	 | Enable colorized output.  This option is equivalent to defining CLICOLOR in the environment. |
| i	 | For each file, print the file's file serial number (inode number). |
| m	 | Stream output format; list files across the page, separated by commas. |
| n	 |  Display user and group IDs numerically, rather than converting to a user or group name in a long (-l) output.  This option turns on the -l option. |
| o	 | List in long format, but omit the group id. |
| p	 | Write a slash (`/') after each filename if that file is a directory. |
| S	 | Sort files by size |
| T	 | When used with the -l (lowercase letter ``ell'') option, display complete time information for the file, including month, day, hour, minute, second, and year. |
| u	 | Use time of last access, instead of last modification of the file for sorting (-t) or long printing (-l). |
| U	 | Use time of file creation, instead of last modification for sorting (-t) or long output (-l). |
| 1	 | Force output to be one entry per line.  This is the default when output is not to a terminal. |
