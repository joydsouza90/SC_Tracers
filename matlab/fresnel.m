function [reflection,theta2] = fresnel(n1,n2,theta1 )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
    temp = sind(theta1)*n1/n2;
    if (temp>1)
        reflection = 1;
        theta2 = 90; return;
    else
        theta2 = asind(temp);
        r1 = ((n1*cosd(theta1)-n2*cosd(theta2))/(n1*cosd(theta1)+n2*cosd(theta2)))^2;
        r2 = ((n1*cosd(theta2)-n2*cosd(theta1))/(n1*cosd(theta2)+n2*cosd(theta1)))^2;
        reflection = (r1+r2)/2;
    end
end

