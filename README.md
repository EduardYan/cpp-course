# C++ Course

<img width=250 height=250 src="./doc/screenshot.png" />

## How to build ?
```bash
g++ -o bin/showMessage showMessage.cpp
g++ -o bin/colors colors.cpp
g++ -o bin/api api.cpp -lcurl

# Interface
cd ./interface
qmake -project
qmake taskmanager.pro
make

```