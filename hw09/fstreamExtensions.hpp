std::fstream &operator>>(std::fstream &os, std::uint16_t &val) {
  os.read(reinterpret_cast<char *>(&val), sizeof(val));
  return os;
}

std::fstream &operator<<(std::fstream &os, std::uint16_t val) {
  os.write(reinterpret_cast<char *>(&val), sizeof(val));
  return os;
}