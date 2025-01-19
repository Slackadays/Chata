$fa = 0.1;
$fs = 0.1;
length = 56.6;
height = 25.9;
thickness = .16;
padwidth = .30;
padlength = .9;
lipheight = 1;
lipwidth = 1.2;
difference() {
cube([length,height,thickness],center=true);
translate([0,0,0]) {
rotate([0,0,0]) {
    //difference() {
        //cube([5.8, 5.8,thickness+.01],center=true);
        union() {
            for (i = [-2:.4:2]) {
                translate([i,2.401,0]) {
                    cube([padwidth,padlength,thickness+.02],center=true);
                }
            }
            for (i = [-2:.4:2]) {
                translate([i,-2.401,0]) {
                    cube([padwidth,padlength,thickness+.02],center=true);
                }
            }
            for (i = [-2:.4:2]) {
                translate([2.401,i,0]) {
                    cube([padlength,padwidth,thickness+.02],center=true);
                }
            }
            for (i = [-2:.4:2]) {
                translate([-2.401,i,0]) {
                    cube([padlength,padwidth,thickness+.02],center=true);
                }
            }
        }
        //}
        
    
}
}
}
rotate([0,0,45]) {
cube([8, .55, thickness], center=true);
}
rotate([0,0,45]) {
cube([.55, 8, thickness], center=true);
}
translate([-length/2,height/2,-thickness/2]) {
    cube([length, lipwidth, lipheight]);
}
translate([-length/2,-height/2 - lipwidth,-thickness/2]) {
    cube([length, lipwidth, lipheight]);
}
translate([length/2,-height/2 - lipwidth,-thickness/2]) {
    cube([lipwidth, height + 2 * lipwidth, lipheight]);
}
translate([- length/2 - lipwidth,-height/2 - lipwidth,-thickness/2]) {
    cube([lipwidth, height + 2 * lipwidth, lipheight]);
}