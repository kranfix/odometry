// TRANSFORMADE AXIS-ANGLE

void kfxAxisang_2Quat(kfxAxisang_t * axis, kfxQuat_t * q){

	float sa = sin(axis->a/2);
	
	////////// QUATERNION //////////
	q->w = cos((axis->a)/2);
 	q->x = sa * axis->x;
	q->y = sa * axis->y;
	q->z = sa * axis->z;

}

void kfxAxisang_2Rpy(kfxAxisang_t * axis, kfxRpy_t * rpy){

	float ca = (1-cos(axis->a));
	float sa = sin(axis->a);
	float n1 = axis->x;
	float n2 = axis->y;
	float n3 = axis->z;

	m->r[1].e[0] = n3*sa + n1*n2*ca;
	m->r[2].e[0] = -n2*sa + n1*n3*ca;
	m->r[2].e[1] = n1*sa+n2*n3*ca;

	////////// RPY //////////
	rpy->p = -asin(m->r[2].e[0]);	
					
	float cp = cos(rpy->p);		
					
	rpy->r = asin(m->r[2].e[1]/cp);	
	rpy->y = asin(m->r[1].e[0]/cp);	

}

void kfxAxisang_2Mat3(kfxAxisang_t * axis, kfxMat3_t * m){
	
	float ca = (1-cos(axis->a));
	float sa = sin(axis->a);
	float n1 = axis->x;
	float n2 = axis->y;
	float n3 = axis->z;
	float n12 = (axis->x)*(axis->y);
	float n13 = (axis->x)*(axis->z);
	float n23 = (axis->y)*(axis->z);

	////////// MATRIX //////////
	m->r[0].e[0] = 1 - ca*(pow(axis->z,2)+pow(axis->y,2));
	m->r[0].e[1] = -n3*sa + n1*n2*ca;
	m->r[0].e[2] = n2*sa + n1*n3*ca;
	m->r[1].e[0] = n3*sa + n1*n2*ca;
	m->r[1].e[1] = 1 - ca*(pow(axis->z,2)+pow(axis->x,2));
	m->r[1].e[2] = -n1*sa + n2*n3*ca;
	m->r[2].e[0] = -n2*sa + n1*n3*ca;
	m->r[2].e[1] = n1*sa+n2*n3*ca;
	m->r[2].e[2] = 1 - ca*(pow(axis->y,2)+pow(axis->x,2));	

}

