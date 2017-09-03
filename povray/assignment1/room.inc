#include "textures.inc"

//macro for a room
#macro Room(ROOM_MID_X, ROOM_BASE, ROOM_MID_Z, PIGMENT)
    #local TILE =
        texture{
            pigment{
                PIGMENT
            }
            finish {
                diffuse 0.3
                specular 0.8
            }
        } // end of texture

    box{
        <ROOM_MID_X - 15, ROOM_BASE, ROOM_MID_Z - 15>, <ROOM_MID_X + 15, ROOM_BASE + 15, ROOM_MID_Z + 15>
        texture{
            TILE
        }
    }
#end //end of macro
