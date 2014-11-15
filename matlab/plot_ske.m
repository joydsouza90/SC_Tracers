% plot the skeleton of the scene and check the normal
% the handness of the vertex should be consistent

clc;
clear;
close all;

fin = fopen('diamond.asc','r');
points = fscanf(fin,'triangle %f %f %f\n%f %f %f\n%f %f %f\n%f %f %f\n%f %f %f\n');
points
fout = fopen('diamond_trans.asc','w');
translation = [1 0 0 1.5;0 1 0 -4;0 0 1 9;0 0 0 1];

angle_x = 65;
angle_y = 180;
angle_z = 0;

Rx = [1 0 0 0;0 cosd(angle_x) -sind(angle_x) 0;0 sind(angle_x) cosd(angle_x) 0; 0 0 0 1];
Ry = [cosd(angle_y) 0 sind(angle_y) 0; 0 1 0 0;-sind(angle_y) 0 cosd(angle_y) 0; 0 0 0 1];
for ii = 1:length(points)/15
    
    x_o(1) = points(15*(ii-1)+1);  % x1
    y_o(1) = points(15*(ii-1)+2);  % y1
    z_o(1) = points(15*(ii-1)+3);  % z1
    x_o(2) = points(15*(ii-1)+4);  % x2
    y_o(2) = points(15*(ii-1)+5); % y2
    z_o(2) = points(15*(ii-1)+6); % z2
    x_o(3) = points(15*(ii-1)+7); % x3
    y_o(3) = points(15*(ii-1)+8); % y3
    z_o(3) = points(15*(ii-1)+9); % z3    
    s(1) = points(15*(ii-1)+10);
    s(2) = points(15*(ii-1)+11);
    s(3) = points(15*(ii-1)+12);
    
    e(1) =  points(15*(ii-1)+13);
    e(2) =  points(15*(ii-1)+14);
    e(3) =  points(15*(ii-1)+15);

    
    p1 = [x_o(1) y_o(1) z_o(1)];
    p2 = [x_o(2) y_o(2) z_o(2)];
    p3 = [x_o(3) y_o(3) z_o(3)];
    
    
    p1_t = translation*Rx*Ry*[p1 1]';
    p1_t = p1_t(1:3);
    p2_t = translation*Rx*Ry*[p2 1]';
    p2_t = p2_t(1:3);
    p3_t = translation*Rx*Ry*[p3 1]';
    p3_t = p3_t(1:3);   
    
    
    n = cross(p3_t-p2_t,p2_t-p1_t);
    n = n/norm(n);
    n_o = (p1_t+p2_t+p3_t)/3;
    figure(1);
    hold on;
    plot3([p1_t(1) p2_t(1)],[p1_t(2) p2_t(2)],[p1_t(3) p2_t(3)]);
    plot3([p2_t(1) p3_t(1)],[p2_t(2) p3_t(2)],[p2_t(3) p3_t(3)]);
    plot3([p3_t(1) p1_t(1)],[p3_t(2) p1_t(2)],[p3_t(3) p1_t(3)]);
    plot3([n_o(1) n_o(1)+n(1)],[n_o(2) n_o(2)+n(2)],[n_o(3) n_o(3)+n(3)],'r');
    s = [0.9 0.9 0.9];
    fprintf(fout,'triangle %f %f %f\n%f %f %f\n%f %f %f\n%f %f %f\n%f %f %f\nT\n',p1_t(1),p1_t(2),p1_t(3),p2_t(1),p2_t(2),p2_t(3),p3_t(1),p3_t(2),p3_t(3),s(1),s(2),s(3),e(1),e(2),e(3));
end
fclose(fin);
fclose(fout);
xlabel('x');
ylabel('y');
zlabel('z');
view([1 0 1.5])
axis equal;
