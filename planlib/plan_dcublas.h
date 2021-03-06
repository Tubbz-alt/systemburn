/*
   This file is part of SystemBurn.

   Copyright (C) 2012, UT-Battelle, LLC.

   This product includes software produced by UT-Battelle, LLC under Contract No.
   DE-AC05-00OR22725 with the Department of Energy.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the New BSD 3-clause software license (LICENSE).

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   LICENSE for more details.

   For more information please contact the SystemBurn developers at:
   systemburn-info@googlegroups.com

 */
#ifndef __PLAN_DCUBLAS_H
#define __PLAN_DCUBLAS_H

#include <loadstruct.h>

extern void *makeDCUBLASPlan(data *i);  /* creates a plan struct       */
extern int initDCUBLASPlan(void *p);    /* inits plan's vptr           */
extern int execDCUBLASPlan(void *p);    /* run the sleep plan          */
extern void *killDCUBLASPlan(void *p);  /* clean up & free plan & vptr */
extern int parseDCUBLASPlan(char *line, LoadPlan *output);
extern plan_info DCUBLAS_info;

/* DCUBLAS caller data structure */
/**
 * \brief The data structure for the plan. Holds the input and all used info.
 */
typedef struct {
    int device, nGpuThreads, nLoopCount, resultCheck, M;
    size_t arraybytes;
    double *HA, *DA, *DB, *DC;
} DCUBLASdata;

#endif /* __PLAN_DCUBLAS_H */
