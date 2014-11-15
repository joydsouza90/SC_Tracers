clc;
clear;
close all;

width = 256;
height =256;

image = zeros(height,width,3);

FOV = 40;
aspectratio = width/height;

angle = tand(0.5*FOV);

fin = fopen('prism3.asc','r');
points = fscanf(fin,'triangle %f %f %f\n%f %f %f\n%f %f %f\n%f %f %f\n%f %f %f \n%c\n');
triangles = zeros(length(points)/16,16);
for ii = 1:length(points)/16
    triangles(ii,:) = points(16*(ii-1)+1:16*(ii-1)+16);  %x1 y1 z1 x2 y2 z2 x3 y3 z3 nx ny nz 
end
for yy = 0:height-1
    display(['trace ' num2str(yy/height*100) '%']);
    for xx = 0:width-1
        dr = zeros(1,3);
        dr(1) = (2 * ((xx+0.5)/width) -1 )*angle*aspectratio;
        dr(2) = (1 - 2*((yy+0.5)/height))*angle;
        dr(3) = 1;
        dr = dr/norm(dr);
        image(yy+1,xx+1,:) = raytrace([0 0 0],dr,triangles,0);

    end
end
imshow(uint8(image*255));

