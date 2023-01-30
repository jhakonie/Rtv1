## Rtv1 - Ray tracing
- a Hive project where you are required to trace basic shapes: sphere, cylinder, cone, plane.
- Allowed functions: open, write, read, malloc, free, perror, strerror.
- Camera and object transformations are mandatory as is a configuration file.

<p align="left">
  <img src="https://github.com/jhakonie/Rtv1/blob/master/along_z_axis.png" width="45%" height="40%">
  <img src="https://github.com/jhakonie/Rtv1/blob/master/along_x_axis.png" width="45%" height="40%">
</p>

<p align="left">
  <img src="https://github.com/jhakonie/Rtv1/blob/master/along_y_axis.png" width="45%" height="40%">
  <img src="https://github.com/jhakonie/Rtv1/blob/master/random_point_of_view.png" width="45%" height="40%">
</p>

The images above are along the xyz-axes and a random point of view, the pink sphere is at 0,0,0.

## Deployment

To deploy this project run:


```bash
  git clone git@github.com:jhakonie/Rtv1.git rtv1
  cd rtv1
  make
```
SDL2 is included as sources in the root of the repository in a directory called libsdl2.
The Makefile will install it in the root of the repository. SDL2 can be deleted with 'make fclean'.

## Usage

```
To run the program:
    ./Rtv1 <path to configuration file>

For example:
    ./Rtv1 data/test.txt
```
The program reads the configuration file, but there are also hard coded scenes that can be switched to with keys 0-9.
The scene on the left is test.txt, the one on the right is behind key 4.

<p align="left">
  <img src="https://github.com/jhakonie/Rtv1/blob/master/Rtv1.png" width="45%" height="40%">
  <img src="https://github.com/jhakonie/Rtv1/blob/master/all_shapes.png" width="45%" height="40%">
</p>
