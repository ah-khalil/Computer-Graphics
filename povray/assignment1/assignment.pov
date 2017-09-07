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

#declare MyGlass=
    object{
        difference
        {
            cone {
                <0, 0, 0>, 0.3, <0, 1.5, 0>, 0.4
            }
            cone {
                <0, 0.1, 0>, .2, <0, 1.55, 0>, 0.35
            }
            texture {
                Glass

                finish{
                    reflection 0.2
                    phong 1
                }
            }
        }
    }

//ELEMENTS COMMON TO ALL
global_settings{
    assumed_gamma 1.0
    max_trace_level 20
}

#if(clock < 21)
    camera{
        /*location<0, 5.75, 0 + (1.55 * clock)>*/
        location<-7, 10, ROOM_DIST + 25>
        up <0, 1, 0>
        right <1, 0, 0>
        look_at<0, 5.75, ROOM_DIST + 2>
    }
#else
    #local X_MOVE = -8 * cos(radians(90/(clock - 20)));
    #local Y_MOVE = 5.75 + 4.25 * cos(radians(90/(clock - 20)));
    #local Z_MOVE = 31 + 15 * cos(radians(90/(clock - 20)));
    camera{
        location<X_MOVE,Y_MOVE,Z_MOVE>
        up<0, 1, 0>
        right<1, 0, 0>
        look_at<0, 5.75, ROOM_DIST>
    }

    #debug concat("Values is: ", vstr(3, <X_MOVE,Y_MOVE,Z_MOVE>, ", ", 0, 2))
#end

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
    <0, 14, 0>
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
    #local LIGHT_POS = 15;
    <0, 5.75, LIGHT_POS>
    color Blue
    #if(clock > 9 & clock < 18)
        translate<0, 0, LIGHT_POS + 3 + (clock - 10)>
    #end
}

//END OF CONNECTION TUBE

//ELEMENTS OF ROOM 2
light_source{
    <0, 14, ROOM_DIST + 15>
    color White
    area_light <1, 0, 0>, <0, 1, 0>, 2, 2
    adaptive 1
    jitter
    looks_like{ lightbulb }
    fade_distance 5
    fade_power 1
}

light_source{
    <8.5, 9.00, ROOM_DIST - 4>
    color Yellow
    rotate<0, 0, 0>
}

object{
    Computer()
    rotate<0, 180, 0>
    translate<0, 4.125, (ROOM_DIST + 15) - 14.1>
}

object{
    Chair(3.75, DMFWood4, Chrome_Metal)
    rotate<180, 140, 0>
    translate<-4, 5, (ROOM_DIST + 13) - 8.5>
}

object{
    Table(0, 4, 0, DMFWood1, Polished_Chrome)
    rotate<0, 180, 0>
    translate<0, 0, (ROOM_DIST + 15) - 13>
}

object{
    MyGlass
    translate<-2, 4, 27.5>
}

object{
    Room(0, 0, ROOM_DIST + 15, ROOM_PIG_2)
}
//END ROOM 2
