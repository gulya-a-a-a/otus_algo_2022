std::fstream &operator>>(std::fstream &os, short &val) {
  os.read(reinterpret_cast<char *>(&val), sizeof(val));
  return os;
}

std::fstream &operator<<(std::fstream &os, short val) {
  os.write(reinterpret_cast<char *>(&val), sizeof(val));
  return os;
}