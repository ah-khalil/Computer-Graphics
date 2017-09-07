#macro Computer()
    #local Screen =
        object{
            Round_Box(
                <0, 0, 0>, <2.7, 2, 0>, 0.1, true
            )
        }
    difference{
        union{
            prism {
                conic_sweep
                linear_spline
                2.33,
                4,
                5,
                <0.4,0.625>, <-0.4,0.625>, <-0.4, 0>, <0.4,0>, <0.4,0.5>
                translate<0, -3, 0.255>
                rotate <270, 0, 0>
                scale <1, 1, 1>
            }
            cylinder{
                <0, 0, 0>, <0, 0.255, 0>, 0.5
                open
            }
            texture{
                normal{
                    bump_map{
                        jpeg "texture_materials/plastic_bump.jpg"
                        bump_size 1
                        interpolate 2
                    }
                }
                finish{
                    diffuse 0.3
                    specular 0.8
                }
            }
        }
        object{
            Screen
            translate<-1.35, 0.505, -0.91>
        }
    }
#end
