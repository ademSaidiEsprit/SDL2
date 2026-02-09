# install sdl2 dependencies for ( ubuntu ) 
```
sudo apt update  
sudo apt install libsdl-mixer-dev
sudo apt install libsdl2-ttf-dev
```
# compile the code 
```
gcc main.c -o app `sdl2-config --cflags --libs` -lSDL2_mixer
gcc main.c -o app `sdl2-config --cflags --libs` -lSDL2_ttf
```
## make a executable desktop app
```
nano ~/Desktop/myapp.desktop
```
## write into it :

```
[Desktop Entry]
Type=Application
Name=My App
Exec=/home/path/to/myapp
Icon=/home/path/to/icons/myicon.png
Terminal=false
```
## make it executable file 
```
chmod +x ~/Desktop/myapp.desktop
```
right clik Allow lunching
