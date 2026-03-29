# BSD-Coreutils
BSD-coreutils is a set of basic utilities like cp, ls and mv (so this project is an alternative to GNU Coreutils). These are based on the 
NetBSD utils but there OpenBSD and FreeBSD too. In some cases  X utility does not exit in *BSD, so the solution for that is a reimplementation like:
- nproc
- hostid
Other utilities are also modified a little bit to has extra function for replacing gnu utils ( ls --> dir & vdir, etc ). 

# Deps
- bmake
- libacl
