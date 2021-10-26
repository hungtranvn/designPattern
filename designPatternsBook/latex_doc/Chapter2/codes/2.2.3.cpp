template<class Key>
bool cmp(Key k1, Key k2);

template<class Key>
struct CMP{
  bool operator()(Key k1, Key  k2);
};

