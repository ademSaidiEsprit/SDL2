# install dependencices for ubuntu 
```
sudo apt update  
sudo apt install libsdl-mixer-dev
```
# compile the code 
```
gcc main.c -o app `sdl2-config --cflags --libs` -lSDL2_mixer
```

