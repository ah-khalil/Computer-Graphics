#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"
#include "table.inc"
#include "room.inc"
#include "lightbulb.inc"
#include "chair.inc"

global_settings{
    assumed_gamma 1.0
}

camera{
    location<12, 8, 10>
    up <0, 1, 0>
    right <1, 0, 0>
    look_at<0, 0, 0>
}

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


object{
    Chair(3.75, DMFWood4)
    translate<0, 0, 11>
}

object{
    Table(0, 4, 0, DMFWood1)
    translate<0, 0, 13>
}
object{
    Room(0, 0, 0, Brown_Agate)
}
