These are function that i use a lot for c stuff, that i will keep updating ig


# Build and install
```
cmake .
make
sudo make install # installs headers to `/usr/lib/clib` and static libs to `/usr/lib/clib`
```
# Use 
## cmake
```
find_library(CLIB_LIB clib HINTS /usr/lib/clib)
target_link_libraries(your-project ${CLIB_LIB})
```




