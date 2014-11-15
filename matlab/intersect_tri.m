function  [inter,t] = intersect_tri (origin,direction,triangle)
    v0 = triangle(1:3);
    v1 = triangle(4:6);
    v2 = triangle(7:9);
    edge1 = v1 - v0;
    edge2 = v2 - v0;
    pvec = cross(direction,edge2);
    det = edge1*pvec';
    if (det == 0) 
        inter = false; t = 0; return;
    end
    invDet = 1/det;
    tvec = origin - v0;
    u = tvec*pvec'*invDet;
    if (u<0||u>1) 
        inter = false; t = 0; return;
    end
    qvec = cross(tvec,edge1);
    v = direction*qvec'*invDet;
    if (v<0||v+u>1)
        inter = false; t = 0; return;
    end
    inter = true;
    t = edge2*qvec'*invDet;
end