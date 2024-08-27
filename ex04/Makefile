name := ex04

# Kaynak dosyalarını ve başlık dosyalarını tanımlama
src := $(wildcard *.cpp)

header := $(wildcard *.hpp) \
	$(wildcard ../base/Matrix/*.hpp) \
	$(wildcard ../base/Vector/*.hpp) \
	$(wildcard *.hpp)

# Derleyici ve bayraklar
cxx := g++
CXXFLAGS = -std=c++11

# Nesne dosyalarını tanımlama
obj := $(src:.cpp=.o)

# Varsayılan hedef
all: $(name)

# İkili dosyayı oluşturma
$(name): $(obj) $(header)
	$(cxx) $(CXXFLAGS) $(obj) -o $(name)

# Nesne dosyalarını oluşturma
%.o: %.cpp $(header)
	$(cxx) $(CXXFLAGS) -c $< -o $@

# Temizlik hedefi
clean:
	rm -f $(obj)

# Temizlik ve ikili dosyayı kaldırma
fclean: clean
	rm -f $(name)

# Temizlik ve yeniden oluşturma
re: fclean all

.PHONY: all clean fclean re
