#!/usr/bin/bash

echo "Building image . . . "
sudo docker build -t prestonbridgers/cotb-dev .
echo "Done building image."

echo "Running container . . . "
sudo docker run -v /home/bridgerspc/Code/curse-of-the-blind:/home/cotb -dt --name cotb prestonbridgers/cotb-dev
echo "Done running container"

echo "Shelling into container"
sudo docker exec -it cotb bash
