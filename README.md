# SocialMediaPlatformCPP
Hi! This repository includes a simple Social Media Platform implementation in C++.  The project represents an example for OOP, while heap usage can also be observed on the implementation.

I will be uploading the files in two steps: one will include source files (.h) and one will include implementation files (.cpp). It is a good practice to create files such way, because source files give the necessary utilization information to the user, while protecting the implementation the developer does not share. 

I should also mention that this is a CS201 (Fundamental Structures of Computer Science) homework given in Bilkent University (İhsan Doğramacı Bilkent University), written by TA Burak Ferit Aktan.

The following are the functionalities of this project:
1. Add a new content creator
2. Remove a content creator
3. Content creator adds a new content
4. Content creator removes a content
5. Add a regular user
6. Remove a regular user
7. A regular user follows a content creator
8. A regular user unfollows a content creator
9. Show the list of all regular users following a content creator (in sorted order according to their IDs)
10. Show the list of all contents of a content creator (in sorted order according to their IDs)
11. Show the list of all regular users (in sorted order according to their IDs)
12. Show the list of all content creators (in sorted order according to their IDs)

**Add a regular user**: The social media platform will allow users to sign up with an ID and a name.
Since the regular user IDs must be unique, the system must check whether or not the specified regular
user ID already exists, and if it exists, it must not allow the operation and display a warning message.
Initially, a regular user is not following any content creator.
Example log messages:
Added regular user 6.
Cannot add regular user. There is already a regular user with ID 6.

**Remove a regular user**: The social media platform will allow removing regular user accounts. If the
regular user does not exist, the system must display a warning message.
Example log messages:
Removed regular user 6.
Cannot remove regular user. There is no regular user with ID 6.
1

**Add a new content creator**: The social media platform will allow new content creators to sign up
with an ID and a name. Since the content creator IDs must be unique, the system must check whether
or not the specified content creator ID already exists, and if it exists, it must not allow the operation
and display a warning message. Initially, a content creator is not followed by any users and does not
have any content.
Example log messages:
Added content creator 6.
Cannot add content creator. There is already a content creator with ID 6.

**Remove a content creator**: The social media platform will allow removing content creator accounts.
If the content creator does not exist, the system must display a warning message.
Example log messages:
Removed content creator 6.
Cannot remove content creator. There is no content creator with ID 6.

**Content creator adds a new content**: The social media platform will allow content creators to
share new contents with a content ID and a title. Since the content IDs must be unique throughout the
system, the system must check whether or not the specified content ID already exists, and if it exists,
the system must not allow the operation and display a warning message. If the given content creator ID
does not exist, the system must not allow the operation and display a warning message.
Example log messages:
Added content 6.
Cannot add content. There is already a content with ID 6.
Cannot add content. There is no content creator with ID 7.
Note: If the following two happen at the same time: 1) content ID already exists and 2) content creator
does not exist, then the log message should be in the following format: Cannot add content. There is
already a content with ID 6.

**Content creator removes a content**: Contents can be removed by specifying their content creator
ID and content ID. If the content creator ID does not exist, the system must not allow the operation
and display a warning message. If the content creator does not have a content with the given ID, the
system must not allow the operation and display a warning message.
Example log messages:
Removed content 6.
Cannot remove content. There is no content creator with ID 7.
Cannot remove content. There is no content with ID 6 shared by content creator with ID 7.

**A regular user follows a content creator**: The social media platform will allow regular users to
follow content creators. If the content creator ID and/or regular user ID does not exist, the system
must display a warning message. If the user is already following the content creator, do not perform the
operation and display a warning message.
Example log messages:
Regular user with ID 5 followed content creator with ID 6.
Cannot follow. Regular user and/or content creator ID does not exist.
Cannot follow. The user is already following the content creator.

**A regular user unfollows a content creator**: The social media platform will allow regular users to
unfollow content creators. If the content creator ID and/or regular user ID does not exist, the system
should not perform the operation and should display a warning message. If the user is not following the
content creator, do not perform the operation and display a warning message.
Example log messages:
Regular user with ID 6 unfollowed content creator with ID 7.
2
Cannot unfollow. Regular user and/or content creator ID does not exist.
Cannot unfollow. The user is not following the content creator.

**Show the list of all contents of a content creator (in sorted order according to their IDs)**:
The social media platform will allow the display of a list of contents shared by a content creator in
ASCENDING ORDER according to content IDs. If the content creator ID does not exist, the system
should display a warning message.
Example log message 1:
Contents of content creator with ID 6:
1
6
Example log message 2:
Contents of content creator with ID 6:
None
Example log message 3:
Cannot show. There is no content creator with ID 6.

**Show the list of all regular users following a content creator (in sorted order according
to their IDs)**: The social media platform will allow the display of a list of regular users following a
content creator in ASCENDING ORDER according to regular user IDs. If the content creator ID does
not exist, the system should display a warning message. Example log message 1:
Regular users following content creator with ID 6:
1
6
Example log message 2:
Regular users following content creator with ID 6:
None
Example log message 3:
Cannot show. There is no content creator with ID 6.

**Show the list of all regular users (in sorted order according to their IDs)**: The social media
platform will allow the display of a list of all regular users’ IDs and names. The entries should be in
ASCENDING ORDER according to IDs.
Example log message 1:
Regular users in the social media platform:
None
Example log message 2:
Regular users in the social media platform:
1, Alper
4, Merve
6, Ayse

**Show the list of all content creators (in sorted order according to their IDs)**: The social
media platform will allow the display of a list of all content creators’ IDs, names, number of followers
and number of contents. The entries should be in ASCENDING ORDER according to IDs.
Example log message 1:
Content creators in the social media platform:
None
Example log message 2:
Content creators in the social media platform:
1, Gamer, 3 follower(s), 0 content(s)
3, Lonely Artist, 2 follower(s), 1 content(s)
