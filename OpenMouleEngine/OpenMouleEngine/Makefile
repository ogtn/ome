#Oui, c'est honteux, c'est juste pour compter les lignes et compiler à l'arrache :D

all:
	g++ -o ome -Wall -ansi core/src/*.cpp loaders/src/*.cpp -Icore/include -Iloaders/include -Icore/inline -lGLEW -lglfw -lIL

lines:
	wc -l data/shaders/*.frag data/shaders/*.vert | sort -n
	wc -l core/*/*pp core/*/*.inl loaders/*/*pp | sort -n
