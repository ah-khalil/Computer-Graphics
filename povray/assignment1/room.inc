#include "textures.inc"

#declare FACTOR = 2;

//macro for a room
#macro Room(ROOM_MID_X, ROOM_BASE, ROOM_MID_Z)
    #local TILE =
        texture{
            pigment{
                brick
                color White
                color rgb<0.1, 0.1, 0.1>
                brick_size <0.25 * 10, 0.125 * 25, 0.25 * 10>
                mortar 0.025
        }
        finish {
            phong 0.125
        }
    } // end of texture

    box{
        <ROOM_MID_X - 15, ROOM_BASE, ROOM_MID_Z - 15>, <ROOM_MID_X + 15, ROOM_BASE + 15, ROOM_MID_Z + 15>
        texture{
            TILE
        }
    }
#end //end of macro
