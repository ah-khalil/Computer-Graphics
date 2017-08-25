#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"

//dimensions of Round_Box
#declare RB_X = 2.5;
#declare RB_Y = RB_X;
#declare RB_Z = RB_X;

//Translation of text B
#declare B_Trans_X = (RB_X / 2) - 0.5;
#declare B_Trans_Y = (RB_Y / 2) - 0.625;


global_settings{
    assumed_gamma 1.0
}

camera{
    location <RB_X / 2, RB_Y / 2, -5>
    up <0, 1, 0>
    right <1, 0, 0>
    look_at <RB_X / 2, RB_Y / 2, RB_Z / 2>
}

union{
    object{
        //Round_Box(A, B, WireRadius, Merge)
        Round_Box(<0, 0, 0>, <RB_X, RB_Y, RB_Z>, 0.3, 0)
        texture{
            pigment{
                color Red
            }
            finish{
                phong 1
            }
        } //end of texture
        scale<1,1,1>
        rotate<0,0,0>
        translate<0,0,0>
    }
    text{
        ttf "cyrvetic.ttf" "B" 1, 0
        pigment {
            White
        }
        scale<2,2,2>
        translate<B_Trans_X, B_Trans_Y, -0.05>
    }
}

light_source{
    <RB_X / 2, 3, -2> color White
    rotate<0, 0, 0>
}
