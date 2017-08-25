#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"
#include "table.inc"
#include "room.inc"

global_settings{
    assumed_gamma 1.0
}

camera{
    location<-7, 15, -10>
    up <0, 1, 0>
    right <1, 0, 0>
    look_at<5, 10, -3>
}

light_source{
    <0, 10, 0> White
}

object{
    Table(0, 4, 0, DMFWood1)
}
object{
    Room(0, 0, 0, Tan_Wood)
}
