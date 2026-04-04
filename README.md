# BSD-Coreutils
BSD-coreutils is a set of basic utilities like cp, ls and mv (so this project is an alternative to GNU Coreutils). 
These are only based on NetBSD, mostly utilities does not have any change.

# Deps
- bmake
- libacl
- libmd

# What happened to truncate, arch and other commands?
Those commands were from OpenBSD and FreeBSD.

# Why false and true are shell scripts?
In NetBSD, they are shell scripts. Before they were written in C they come from OpenBSD
