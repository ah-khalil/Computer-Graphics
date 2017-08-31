#macro Computer()
    union{
        difference{
            prism {
                conic_sweep
                linear_spline
                2.33,
                4,
                5,
                <0.4,0.625>,<-0.4,0.625>,<-0.4, 0>,<0.4,0>,<0.4,0.5>
                rotate <270, 0, 0>
                translate <0, 4.375, 17.35>
                scale <1, 1, 1>
                pigment { gradient y scale .2 }
            }
            object{
                Round_Box(
                    <-1.35, 4.5, 12>, <1.35, 6.5, 13>, 0.1, true
                )
                pigment{
                    color White
                }
                translate<0, 0.165, 1>
            }
        }
        object{
            Round_Box(
                <-1.35, 4.5, 12>, <1.35, 6.5, 12>, 0.1, true
            )
            pigment{
                color Blue
            }
            texture{
                Chrome_Metal
            }
            finish{
                phong 1
            }
            translate<0, 0.165, 1.405>
        }
        cylinder{
            <0, 4.125, 14.1>, <0, 4.375, 14.1>, 0.5
            open
            pigment{
                color Gray
            }
        }
        light_source{
            <0, 5.5, 12>
            color Blue
        }
    }
#end