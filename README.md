# ROSNeuro Visualizer package

The package provides **neuroviz** stand-alone application to visualize **NeuroFrame** messages ([rosneuro_msgs](https://github.com/rosneuro/rosneuro_msgs)) published in a given topic. 

**neuroviz** is a GUI interface based on Qt and it is designed to accept external plugin for custom visualization panels (not available yet). Currently, **neuroviz** provides plugins to visualize the temporal evolution (scope) of EEG and EMG data read from **NeuroFrame** message. Furthermore, it allows to filter the incoming data (low-pass and high-pass butterworth filters with order 2), to apply spatial filters (Common Average Reference, Reference Electrode), to select specific channels and to enlarge or reduce the visualization window. Finally, the application provides information about the rate and the sequence number of the incoming **NeuroFrame** messages.

## Requirements
rosneuro_visualizer has been tested with the following configuration:
- **Ubuntu 18.04.05 LTS Bionic Beaver** and **ROS Melodic**
- **Ubuntu 20.04.02 LTS Focal Fossa** and **ROS Noetic**

rosneuro_visualizer depends on the following libraries:
- Qt5 (available on ubuntu: qt5-default)
- rtfilter (available on ubuntu: librtfilter-dev) 

## Usage
**neuroviz** is launched from the terminal as ROS package. Once the application opens, it is possible to select the reading topic from the GUI.
```
rosrun rosneuro_visualizer neuroviz
```
