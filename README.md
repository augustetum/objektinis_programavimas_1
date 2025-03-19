# objektinis_programavimas_1



| Testuojamos sistemos parametrai |  |
| -------------------------------- | - |
| CPU | Apple M1 |
| RAM | 8GB, 8 core |
| SSD | 256GB | 


<h2>Konteinerių tyrimas</h2>

| Studentų kiekis faile | Konteinerio tipas | Failo nuskaitymas | Rikiavimas | Skirstymas | Programos veikimas |
| --------- | ----------------- | ----------------- | ---------- | ---------- | ------------------ |
| 1000 | Vektoriai (vectors) | 0.00654578s | 7.24307e-05s | 0.00132085s | 0.00793914s |
| 1000 |  Dvipusė eilė (deque) | 0.00616018s | 8.6486e-05s | 0.00107772s | 0.00732449s |
| 1000 | Sąrašai (list) | 0.0058434s | 5.9694e-05s | 0.00142793s | 0.00733115s |
| |
| 10 000 | Vektoriai (vectors) | 0.0338688s | 0.000466028s | 0.00966726s | 0.0440022s |
| 10 000 |  Dvipusė eilė (deque) | 0.0339212s | 0.000529736s | 0.008725s | 0.0431759s |
| 10 000 | Sąrašai (list) | 0.0339323s | 0.000741709s | 0.0104051s | 0.0450791s |
| |
| 100 000 | Vektoriai (vectors) | 0.400789s | 0.0053029s | 0.137764s | 0.543856s |
| 100 000 | Dvipusė eilė (deque) | 0.399359s | 0.00520086s | 0.10217s | 0.506729s |
| 100 000 | Sąrašai (list) | 0.396128s | 0.0176462s | 0.131789s | 0.545564s | 
| |
| 1 000 000 | Vektoriai (vectors) | 1.60673s | 0.0425555s | 0.849124s | 2.49841s |
| 1 000 000 | Dvipusė eilė (deque) | 1.69874s | 0.056697s | 0.955653s | 2.71109s |
| 1 000 000 | Sąrašai (list) | 1.66162s | 0.527589s | 1.32249s | 3.5117s |
| |
| 10 000 000 | Vektoriai (vectors) | 56.5568s | 0.765428s | 16.9947s | 74.3169s |
| 10 000 000 | Dvipusė eilė (deque) | 53.5321s | 0.796377s | 15.8749s | 70.2034s |
| 10 000 000 | Sąrašai (list) | 53.4425s | 9.82805s | 25.8748s | 89.1454s | 

<h2>1 Strategija | Tyrimo rezultatai</h2>
<p> Įvykdytos trys iteracijos, visose iteracijose pasirinktas rikiavimas pagal galutinį balą su vidurkiu</p>

| Studentų kiekis faile | Konteinerio tipas | Programos veikimo laikas |
| --------------------- | ------------------ | ------------ |
| 1000 | Vektoriai (vectors) | 0.0171251s |
| 1000 | Dvipusė eilė (deque) | 0.0129133s |
| 1000 | Sąrašai (list) | 0.011015s |
| |
| 10 000 | Vektoriai (vectors) | 0.069089s |
| 10 000 | Dvipusė eilė (deque) | 0.066101s |
| 10 000 | Sąrašai (list) | 0.0670562s |
| |
| 100 000 | Vektoriai (vectors) | 0.715121s |
| 100 000 | Dvipusė eilė (deque) | 0.788766s |
| 100 000 | Sąrašai (list) | 0.77075s |
| |
| 1 000 000 | Vektoriai (vectors) | 4.19476s |
| 1 000 000 | Dvipusė eilė (deque) | 4.62663s |
| 1 000 000 | Sąrašai (list) | 5.77609s |
| |
| 10 000 000 | Vektoriai (vectors) | 78.007s | 
| 10 000 000 | Dvipusė eilė (deque) | 69.4141s | 
| 10 000 000 | Sąrašai (list) | 79.2014s |
