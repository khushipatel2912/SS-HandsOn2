/* 

Name : 17a.c
Author : Khushi Patel
Description : Write a program to execute ls -l | wc.
a. use dup

Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[0]);
        dup(fd[1]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        close(fd[1]);
        dup(fd[0]);
        execlp("wc", "wc", NULL);
    }

    return 0;
}





/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 17a.c -o 17a
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./17a
total 684
-rwxrwxr-x 1 khushi khushi 16184 Sep 20 15:54 10a
-rw-rw-r-- 1 khushi khushi   753 Sep 20 15:55 10a.c
-rwxrwxr-x 1 khushi khushi 16136 Sep 20 15:56 10b
-rw-rw-r-- 1 khushi khushi   764 Sep 20 15:59 10b.c
-rwxrwxr-x 1 khushi khushi 16184 Sep 20 15:59 10c
-rw-rw-r-- 1 khushi khushi   863 Sep 20 16:06 10c.c
-rwxrwxr-x 1 khushi khushi 16216 Sep 20 16:06 11
-rw-rw-r-- 1 khushi khushi  1148 Sep 20 16:08 11.c
-rwxrwxr-x 1 khushi khushi 16208 Sep 20 16:11 12
-rw-rw-r-- 1 khushi khushi   958 Sep 20 16:12 12.c
-rwxrwxr-x 1 khushi khushi 16048 Sep 20 16:16 13a
-rw-rw-r-- 1 khushi khushi   779 Sep 20 16:22 13a.c
-rwxrwxr-x 1 khushi khushi 16104 Sep 20 16:23 13b
-rw-rw-r-- 1 khushi khushi   837 Sep 20 16:25 13b.c
-rwxrwxr-x 1 khushi khushi 16216 Sep 20 16:25 14
-rw-rw-r-- 1 khushi khushi   850 Sep 20 16:35 14.c
-rwxrwxr-x 1 khushi khushi 16216 Sep 20 16:35 15
-rw-rw-r-- 1 khushi khushi   847 Sep 20 16:35 15.c
-rwxrwxr-x 1 khushi khushi 16216 Sep 20 16:40 16
-rw-rw-r-- 1 khushi khushi  1403 Sep 20 16:41 16.c
-rwxrwxr-x 1 khushi khushi 16176 Sep 20 16:43 17a
-rw-rw-r-- 1 khushi khushi   456 Sep 20 16:43 17a.c
-rw-rw-r-- 1 khushi khushi   456 Sep 20 16:43 17.c
-rw-rw-r-- 1 khushi khushi   219 Sep 20 10:53 18.c
-rw-rw-r-- 1 khushi khushi   145 Sep 20 10:54 19a.c
-rw-rw-r-- 1 khushi khushi   146 Sep 20 10:55 19b.c
-rw-rw-r-- 1 khushi khushi   206 Sep 20 10:55 19c.c
-rw-rw-r-- 1 khushi khushi   149 Sep 20 10:56 19d.c
-rw-rw-r-- 1 khushi khushi   154 Sep 20 10:56 19e.c
-rwxrwxr-x 1 khushi khushi 16160 Sep 20 08:06 1a
-rw-rw-r-- 1 khushi khushi  1024 Sep 20 09:14 1a.c
-rwxrwxr-x 1 khushi khushi 16120 Sep 20 08:18 1b
-rw-rw-r-- 1 khushi khushi  1077 Sep 20 09:14 1b.c
-rwxrwxr-x 1 khushi khushi 16184 Sep 20 09:13 1c
-rw-rw-r-- 1 khushi khushi  1089 Sep 20 09:14 1c.c
-rwxrwxr-x 1 khushi khushi 16136 Sep 20 09:17 2
-rw-rw-r-- 1 khushi khushi   189 Sep 20 10:56 20.c
-rw-rw-r-- 1 khushi khushi   189 Sep 20 10:57 21.c
-rw-rw-r-- 1 khushi khushi   215 Sep 20 10:58 22.c
-rw-rw-r-- 1 khushi khushi   227 Sep 20 10:58 23.c
-rw-rw-r-- 1 khushi khushi   187 Sep 20 10:59 24.c
-rw-rw-r-- 1 khushi khushi   429 Sep 20 10:59 25.c
-rw-rw-r-- 1 khushi khushi   175 Sep 20 11:00 26.c
-rw-rw-r-- 1 khushi khushi   186 Sep 20 11:01 27a.c
-rw-rw-r-- 1 khushi khushi   195 Sep 20 11:01 27b.c
-rw-rw-r-- 1 khushi khushi   194 Sep 20 11:01 28.c
-rw-rw-r-- 1 khushi khushi   150 Sep 20 11:02 29.c
-rw-rw-r-- 1 khushi khushi  1413 Sep 20 09:17 2.c
-rwxrwxr-x 1 khushi khushi 16232 Sep 20 09:22 3
-rw-rw-r-- 1 khushi khushi   189 Sep 20 11:03 30a.c
-rw-rw-r-- 1 khushi khushi   218 Sep 20 11:04 30b.c
-rw-rw-r-- 1 khushi khushi   177 Sep 20 11:04 30c.c
-rw-rw-r-- 1 khushi khushi   177 Sep 20 11:04 30d.c
-rw-rw-r-- 1 khushi khushi   212 Sep 20 11:06 31a.c
-rw-rw-r-- 1 khushi khushi   214 Sep 20 11:06 31b.c
-rw-rw-r-- 1 khushi khushi   240 Sep 20 11:07 32a.c
-rw-rw-r-- 1 khushi khushi   232 Sep 20 11:08 32b.c
-rw-rw-r-- 1 khushi khushi   254 Sep 20 11:08 32c.c
-rw-rw-r-- 1 khushi khushi   210 Sep 20 11:08 32d.c
-rw-rw-r-- 1 khushi khushi   171 Sep 20 11:08 33.c
-rw-rw-r-- 1 khushi khushi   165 Sep 20 11:09 34a.c
-rw-rw-r-- 1 khushi khushi   175 Sep 20 11:10 34b.c
-rw-rw-r-- 1 khushi khushi  1123 Sep 20 09:22 3.c
-rwxrwxr-x 1 khushi khushi 16000 Sep 20 09:23 4
-rw-rw-r-- 1 khushi khushi   745 Sep 20 09:23 4.c
-rwxrwxr-x 1 khushi khushi 16000 Sep 20 09:25 5
-rw-rw-r-- 1 khushi khushi  1367 Sep 20 09:25 5.c
-rwxrwxr-x 1 khushi khushi 16200 Sep 20 09:30 6
-rw-rw-r-- 1 khushi khushi   752 Sep 20 09:30 6.c
-rwxrwxr-x 1 khushi khushi 16248 Sep 20 09:30 7
-rw-rw-r-- 1 khushi khushi   822 Sep 20 09:30 7.c
-rwxrwxr-x 1 khushi khushi 16080 Sep 20 09:39 8a
-rw-rw-r-- 1 khushi khushi   681 Sep 20 09:39 8a.c
-rwxrwxr-x 1 khushi khushi 16080 Sep 20 09:41 8b
-rw-rw-r-- 1 khushi khushi   678 Sep 20 09:58 8b.c
-rwxrwxr-x 1 khushi khushi 16040 Sep 20 10:14 8c
-rw-rw-r-- 1 khushi khushi   635 Sep 20 10:16 8c.c
-rwxrwxr-x 1 khushi khushi 16128 Sep 20 10:18 8d
-rw-rw-r-- 1 khushi khushi   665 Sep 20 10:18 8d.c
-rwxrwxr-x 1 khushi khushi 16128 Sep 20 10:19 8e
-rw-rw-r-- 1 khushi khushi   940 Sep 20 10:22 8e.c
-rwxrwxr-x 1 khushi khushi 16088 Sep 20 10:22 8f
-rw-rw-r-- 1 khushi khushi   876 Sep 20 10:22 8f.c
-rwxrwxr-x 1 khushi khushi 16088 Sep 20 10:24 8g
-rw-rw-r-- 1 khushi khushi   886 Sep 20 10:24 8g.c
-rwxrwxr-x 1 khushi khushi 16168 Sep 20 10:45 9
-rw-rw-r-- 1 khushi khushi   866 Sep 20 10:45 9.c
^C



*/
