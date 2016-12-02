# K
echo "compileing libk.so"
echo "g++ -o Lib/K/libk.so -shared -fPIC Lib/K/k.cpp -w"
g++ -o Lib/K/libk.so -shared -fPIC Lib/K/k.cpp -w

# Fasta
echo "compileing Fasta"
echo "g++ Lib/Fasta/fasta.cpp -o Lib/Fasta/fa -w"
g++ Lib/Fasta/fasta.cpp -o Lib/Fasta/fa.exe -w

# Edit-distance
echo "compileing Edit-distance"
echo "g++ Lib/Editd/main.cpp -o Lib/Editd/di -w"
g++ Lib/Editd/main.cpp -o Lib/Editd/di -w

# NW&SW
echo "compileing NW&SW"
echo "g++ Lib/NWSW/main.cpp -o Lib/NWSW/nwsw -w"
g++ Lib/NWSW/main.cpp -o Lib/NWSW/nwsw -w

# DT
echo "compileing DT"
cd Lib/DT
shedskin -n DT
make

echo "finish"
exit
