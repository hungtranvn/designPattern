void DrawPoints (CPaintDC& dc, std::vector<Point>::iterator start, \
                std::vector<Point>::iterator end) {
  for (auto i = start; i != end; ++i)
    dc.SetPixel(i->x, i->y, 0);
}
