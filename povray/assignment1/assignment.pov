#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"
#include "table.inc"
#include "room.inc"
#include "lightbulb.inc"
#include "chair.inc"
#include "computer.inc"

#declare ROOM_DIST = 100;

//ELEMENTS COMMON TO ALL
global_settings{
    assumed_gamma 1.0
}

camera{
    location<ROOM_DIST, 10, ROOM_DIST/2>
    up <0, 1, 0>
    right <1, 0, 0>
    look_at<0, 0, ROOM_DIST/2>
}

plane{
    y, 0
    texture{
        White_Marble
        scale<0.75, 0.75, 0.75>
    }
    finish{
        reflection 0.2
    }
}
//END COMMON

//ELEMENTS OF ROOM 1
light_source{
    <0, 9, 0>
    color White
    area_light <1, 0, 0>, <0, 1, 0>, 2, 2
    adaptive 1
    jitter
    looks_like{ lightbulb }
    fade_distance 5
    fade_power 1
}

object{
    Computer()
    translate<0, 4.125, 14.1>
}

object{
    Chair(3.75, DMFWood4)
    translate<0, 0, 11>
}

object{
    Table(0, 4, 0, DMFWood1)
    translate<0, 0, 13>
}
object{
    Room(0, 0, 0)
}
//END ROOM 1

//CONNECTION TUBE
cylinder{
    <0, 0, 0>, <0, ROOM_DIST, 0>, 1.5
    open
    rotate<270, 0, 0>
    translate<0, 4, ROOM_DIST>
    pigment{
        color Pink
    }
}

//ELEMENTS OF ROOM 2
light_source{
    <0, 9, ROOM_DIST>
    color White
    area_light <1, 0, 0>, <0, 1, 0>, 2, 2
    adaptive 1
    jitter
    looks_like{ lightbulb }
    fade_distance 5
    fade_power 1
}

object{
    Computer()
    rotate<0, 180, 0>
    translate<0, 4.125, ROOM_DIST - 14.1>
}

object{
    Chair(3.75, DMFWood4)
    rotate<0, 180, 0>
    translate<0, 0, ROOM_DIST - 11>
}

object{
    Table(0, 4, 0, DMFWood1)
    rotate<0, 180, 0>
    translate<0, 0, ROOM_DIST - 13>
}
object{
    Room(0, 0, ROOM_DIST)
}
//END ROOM 2
