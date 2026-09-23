void scroll_castle_inside_dl_LAYER_ALPHA_inside_castle_seg7_dl_07038350_mesh_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 4;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_LAYER_ALPHA_inside_castle_seg7_dl_07038350_mesh_mesh_layer_5_vtx_1);

	deltaX = (int)(0.5 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_castle_inside() {
	scroll_castle_inside_dl_LAYER_ALPHA_inside_castle_seg7_dl_07038350_mesh_mesh_layer_5_vtx_1();
};
