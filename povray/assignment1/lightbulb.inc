#declare lightbulb =
union {
    merge {
        sphere {
            <0, 0, 0>,1
        }
        cylinder {
            <0, 0, 1>, <0, 0, 0>, 1
            scale <0.35, 0.35, 1.0>
            translate  0.5 * z
        }
        texture {
            pigment {
                color rgb <1, 1, 1>
            }
            finish {
                ambient .8
                diffuse .6
            }
        }
    }
    cylinder {
        <0, 0, 1>, <0, 0, 0>, 1
        scale <0.4, 0.4, 0.5>
        texture { Brass_Texture }
        translate  1.5*z
    }
    rotate -90*x
    scale .5
}
