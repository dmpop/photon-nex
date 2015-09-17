#!/bin/bash

# Bash shell script to control
# a Photon-based shutter release
# for SONY NEX and Alpha cameras

device_id="photon_device_id"
access_token="access_token"
counter=1
while [ $counter -le $1 ]
do
    curl https://api.particle.io/v1/devices/$device_id/shutter -d access_token=$access_token -d params=release
    ((counter++))
    sleep $2
done
echo "All done!"
