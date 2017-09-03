#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"
#include "table.inc"
#include "room.inc"
#include "lightbulb.inc"
#include "chair.inc"
#include "computer.inc"

#declare ROOM_DIST = 25;
#declare ROOM_PIG_1 =
    pigment{
        brick
        color White
        color rgb<0.1, 0.1, 0.1>
        brick_size <0.25 * 10, 0.125 * 25, 0.25 * 10>
        mortar 0.025
    }
#declare ROOM_PIG_2 =
    pigment{
        checker pigment{ Pink }, pigment{ Black }
    }

//ELEMENTS COMMON TO ALL
global_settings{
    assumed_gamma 1.0
}

camera{
    location<-15, 8, -15 + (1.33 * clock)>
    up <0, 1, 0>
    right <1, 0, 0>
    look_at<0, 5.75, 15>
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
    <0, 13, 0>
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
    Chair(3.75, DMFWood4, Chrome_Metal)
    rotate<0, -45, 0>
    translate<2.5, 0, 8.5>
}

object{
    Table(0, 4, 0, DMFWood1, Polished_Chrome)
    translate<0, 0, 13>
}
object{
    Room(0, 0, 0, ROOM_PIG_1)

}
//END ROOM 1

//CONNECTION TUBE
object{
    cylinder{
        <0, 0, 0>, <0, ROOM_DIST - 12, 0>, 0.70
        rotate<270, 0, 0>
        texture{
            pigment{
                image_map{
                    png "texture_materials/garbage01.png"
                    map_type 0
                    interpolate 2
                }
            }
            finish{
                phong 1
            }
            rotate<90, 180, 90>
            scale<2, 2, 2>
        }
    }
    translate<0, 5.75, ROOM_DIST + 1.5>
}

light_source{
    <0, 5.75, 20>
    color Blue
    translate<0, 0, 0 + 2.16 * clock>
}

//END OF CONNECTION TUBE

//ELEMENTS OF ROOM 2
light_source{
    <0, 13, ROOM_DIST + 15>
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
    translate<0, 4.125, (ROOM_DIST + 15) - 14.1>
}

object{
    Chair(3.75, DMFWood4, Chrome_Metal)
    rotate<0, 140, 0>
    translate<2.5, 0, (ROOM_DIST + 15) - 8.5>
}

object{
    Table(0, 4, 0, DMFWood1, Polished_Chrome)
    rotate<0, 180, 0>
    translate<0, 0, (ROOM_DIST + 15) - 13>
}
object{
    Room(0, 0, ROOM_DIST + 15, ROOM_PIG_2)
}
//END ROOM 2
