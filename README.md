# For ubuntu users
## * Install sdl2 dependencies 
```
sudo apt update  
sudo apt install libsdl-mixer-dev
sudo apt install libsdl2-ttf-dev
```
## * Compile the code 
```
gcc main.c -o app `sdl2-config --cflags --libs` -lSDL2_mixer
gcc main.c -o app `sdl2-config --cflags --libs` -lSDL2_ttf
```
## * Make a executable desktop app
### 1 create file
```
nano ~/Desktop/myapp.desktop
```
### 2 write into it :

```
[Desktop Entry]
Type=Application
Name=My App
Exec=/home/path/to/myapp
Icon=/home/path/to/icons/myicon.png
Terminal=false
```
### 3 make it executable file 
```
chmod +x ~/Desktop/myapp.desktop
```
### 4 right clik Allow lunching
