//
// Created by prasanga on 3/2/19.
//

#ifndef GRAPHICSPROJECT_ALGOS_H
#define GRAPHICSPROJECT_ALGOS_H

#include "headers.h"
#include "glutfunctions.h"
void fillTriangle(float axo, float ay, float az, float ar,float ag,float ab, float bxo, float by, float bz, float br,float bg,float bb, float cxo, float cy, float cz, float cr,float cg,float cb){
    float tempx,tempy,tempr,tempg,tempb, adepth, bdepth, cdepth, tempdepth;
    adepth = axo + ay;
    bdepth = bxo + by;
    cdepth = cxo + cy;
    float ax = cos(isoangle) *(axo - ay) + transx;
    ay = sin(isoangle) * (axo + ay) + az + transy;
    float bx = cos(isoangle) *(bxo - by) + transx;
    by = sin(isoangle) * (bxo + by) + bz + transy;
    float cx = cos(isoangle) *(cxo - cy) + transx;
    cy = sin(isoangle) * (cxo + cy) + cz + transy;
    if(ay==by && by == cy){
        by += 0.00001;
        cy += 0.00002;
    }
    if(ay == by){
        by += 0.00001;
    }
    if(ay == cy){
        cy += 0.00002;
    }
    if(by == cy){
        cy += 0.0002;
    }
    if(by < ay && by < cy){
        tempx = ax;
        tempy = ay;
        tempr = ar;
        tempg = ag;
        tempb = ab;
        tempdepth = adepth;
        ax = bx;
        ay = by;
        ar = br;
        ag = bg;
        ab = bb;
        adepth = bdepth;
        if(tempy  >  cy){
            bx = cx;
            by = cy;
            br = cr;
            bg = cg;
            bb = cb;
            bdepth = cdepth;
            cx = tempx;
            cy = tempy;
            cr = tempr;
            cg = tempg;
            cb = tempb;
            cdepth = tempdepth;
        }
        else{
            bx = tempx;
            by = tempy;
            br = tempr;
            bg = tempg;
            bb = tempb;
            bdepth = tempdepth;
        }
    }
    else if(cy < ay && cy < by){
        tempx = ax;
        tempy = ay;
        tempr = ar;
        tempg = ag;
        tempb = ab;
        tempdepth = adepth;
        ax = cx;
        ay = cy;
        ar = cr;
        ag = cg;
        ab = cb;
        adepth = cdepth;
        cx = tempx;
        cy = tempy;
        cr = tempr;
        cg = tempg;
        cb = tempb;
        cdepth = tempdepth;
        if(tempy  <  by){
            tempx = bx;
            tempy = by;
            tempr = br;
            tempg = bg;
            tempb = bb;
            tempdepth = bdepth;
            bx = cx;
            by = cy;
            br = cr;
            bg = cg;
            bb = cb;
            bdepth = cdepth;
            cx = tempx;
            cy = tempy;
            cr = tempr;
            cg = tempg;
            cb = tempb;
            cdepth = tempdepth;
        }
        else{
            cx = tempx;
            cy = tempy;
            cr = tempr;
            cg = tempg;
            cb = tempb;
            cdepth = tempdepth;
        }
    }
    else{
        if(by > cy){
            tempx = bx;
            tempy = by;
            tempr = br;
            tempg = bg;
            tempb = bb;
            tempdepth = bdepth;
            bx = cx;
            by = cy;
            br = cr;
            bg = cg;
            bb = cb;
            bdepth = cdepth;
            cx = tempx;
            cy = tempy;
            cr = tempr;
            cg = tempg;
            cb = tempb;
            cdepth = tempdepth;
        }
    }
    float px,py,pr,pb,pg,pdepth,  dx1, dx2, dx3,dr1,dr2,dr3,dg1,dg2,dg3,db1,db2,db3,ddepth1, ddepth2, ddepth3,sx,sy,sr,sg,sb,sdepth,ex,ey,er,eg,eb,edepth, db,dg,dr, ddepth;
    if (by-ay > 0) {
        dx1=(bx-ax)/(by-ay);
        dr1=(br-ar)/(by-ay);
        dg1=(bg-ag)/(by-ay);
        db1=(bb-ab)/(by-ay);
        ddepth1 =(bdepth-adepth)/(by-ay);
    } else
        dx1=dr1=dg1=db1=ddepth1=0;

    if (cy-ay > 0) {
        dx2=(cx-ax)/(cy-ay);
        dr2=(cr-ar)/(cy-ay);
        dg2=(cg-ag)/(cy-ay);
        db2=(cb-ab)/(cy-ay);
        ddepth2 = (cdepth - adepth)/(cy - ay);
    } else
        dx2=dr2=dg2=db2=ddepth2=0;

    if (cy-by > 0) {
        dx3=(cx-bx)/(cy-by);
        dr3=(cr-br)/(cy-by);
        dg3=(cg-bg)/(cy-by);
        db3=(cb-bb)/(cy-by);
        ddepth3 = (cdepth - bdepth)/(cy - by);
    } else
        dx3=dr3=dg3=db3=cdepth=0;

    sx = ex = ax;
    sy = ey = ay;
    sr = er = ar;
    sg = eg = ag;
    sb = eb = ab;
    sdepth = edepth = adepth;
    if(dx1 > dx2) {
        for(;sy<=by;sy++,ey++) {
            if(ex-sx > 0) {
                dr=(er-sr)/(ex-sx);
                dg=(eg-sg)/(ex-sx);
                db=(eb-sb)/(ex-sx);
                ddepth=(edepth-sdepth)/(ex-sx);
            } else
                dr=dg=db=ddepth=0;
            px = sx;
            py = sy;
            pr = sr;
            pg = sg;
            pb = sb;
            pdepth = sdepth;
            for(;px < ex;px++) {
                if(depthbuf.count({px,py}) == 0) {
                    putpixel(px, py, pr, pg, pb);
                    depthbuf[{px, py}] = pdepth;
                }
                else if(pdepth <= depthbuf[{px,py}]){
                    putpixel(px, py, pr, pg, pb);
                    depthbuf[{px, py}] = pdepth;
                }
                pr+=dr; pg+=dg; pb+=db; pdepth+=ddepth;
            }
            sx+=dx2; sr+=dr2; sg+=dg2; sb+=db2; sdepth+=ddepth2;
            ex+=dx1; er+=dr1; eg+=dg1; eb+=db1; edepth+=ddepth1;
        }

        ex = bx;
        ey = by;
        er = br;
        eg = bg;
        eb = bb;
        edepth = bdepth;
        for(;sy<=cy;sy++,ey++) {
            if(ex-sx > 0) {
                dr=(er-sr)/(ex-sx);
                dg=(eg-sg)/(ex-sx);
                db=(eb-sb)/(ex-sx);
                ddepth = (edepth - sdepth)/(ex-sx);
            } else dr=dg=db=ddepth=0;
            px = sx;
            py = sy;
            pr = sr;
            pg = sg;
            pb = sb;
            pdepth = sdepth;
            for(;px < ex;px++) {
                if(depthbuf.count({px,py}) == 0) {
                    putpixel(px, py, pr, pg, pb);
                    depthbuf[{px, py}] = pdepth;
                }
                else if(pdepth < depthbuf[{px,py}]){
                    putpixel(px, py, pr, pg, pb);
                    depthbuf[{px, py}] = pdepth;
                }
                pr+=dr; pg+=dg; pb+=db; pdepth+=ddepth;
            }
            sx+=dx2; sr+=dr2; sg+=dg2; sb+=db2; sdepth+=ddepth2;
            ex+=dx3; er+=dr3; eg+=dg3; eb+=db3; edepth+=ddepth3;
        }
    } else {
        for(;sy<=by;sy++,ey++) {
            if(ex-sx > 0) {
                dr=(er-sr)/(ex-sx);
                dg=(eg-sg)/(ex-sx);
                db=(eb-sb)/(ex-sx);
                ddepth=(edepth-sdepth)/(ex-sx);
            } else
                dr=dg=db=ddepth=0;

            px = sx;
            py = sy;
            pr = sr;
            pg = sg;
            pb = sb;
            pdepth = sdepth;
            for(;px < ex;px++) {
                if(depthbuf.count({px,py}) == 0) {
                    putpixel(px, py, pr, pg, pb);
                    depthbuf[{px, py}] = pdepth;
                }
                else if(pdepth < depthbuf[{px,py}]){
                    putpixel(px, py, pr, pg, pb);
                    depthbuf[{px, py}] = pdepth;
                }
                pr+=dr; pg+=dg; pb+=db; pdepth+=ddepth;
            }
            sx+=dx1; sr+=dr1; sg+=dg1; sb+=db1; sdepth+=ddepth1;
            ex+=dx2; er+=dr2; eg+=dg2; eb+=db2; edepth+=ddepth2;
        }
        sx = bx;
        sy = by;
        sr = br;
        sg = bg;
        sb = bb;
        sdepth = bdepth;
        for(;sy<=cy;sy++,ey++) {
            if(ex-sx > 0) {
                dr=(er-sr)/(ex-sx);
                dg=(eg-sg)/(ex-sx);
                db=(eb-sb)/(ex-sx);
                ddepth=(edepth-sdepth)/(edepth-sdepth);
            } else
                dr=dg=db=ddepth=0;

            px = sx;
            py = sy;
            pr = sr;
            pg = sg;
            pb = sb;
            pdepth = sdepth;
            for(;px < ex;px++) {
                if(depthbuf.count({px,py}) == 0) {
                    putpixel(px, py, pr, pg, pb);
                    depthbuf[{px, py}] = pdepth;
                }
                else if(pdepth <= depthbuf[{px,py}]){
                    putpixel(px, py, pr, pg, pb);
                    depthbuf[{px, py}] = pdepth;
                }
                pr+=dr; pg+=dg; pb+=db; pdepth+= ddepth;
            }
            sx+=dx3; sr+=dr3; sg+=dg3; sb+=db3; sdepth+=ddepth3;
            ex+=dx2; er+=dr2; eg+=dg2; eb+=db2; edepth+=ddepth2;
        }
    }
}



#endif //GRAPHICSPROJECT_ALGOS_H
