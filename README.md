# cpp-demo2
 ifs.seekg(0,ios::end);
 int count = (int)ifs.tellg()/sizeof(*this);
ifs.seekg((n-1)*sizeof(*this));
ifs.write(reinterpret_cast<char*>(this), sizeof(*this));
ifs.read(reinterpret_cast<char*>(this), sizeof(*this));
