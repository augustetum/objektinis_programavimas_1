# objektinis_programavimas_1
<h2>Programos aprašymas</h2>
<p>Programa yra skirta apdoroti studentus ir jų akademinių pasiekimų duomenis.</p>
<h4><b> Pradinės programos funkcijos: </b> </h4>

<ol>
    <li>Įvesti visus studentų duomenis ranka</li>
    <li>Įvesti studentų vardus, pavardes, atsitiktine tvarka generuoti pažymius</li>
    <li>Atsitiktinai generuoti studentų vardus, pavardes ir pažymius</li>
    <li>Nuskaityti duomenis iš failo</li>
    <li>Atsitiktinai generuoti failą su studentų duomenimis</li>
</ol>

<p>Programoje taip pat pateiktos <b>trys strategijos</b>, skirtos testuoti skirtingų programos veikimo laiko priklausomybę nuo naudojamų konteinerių (<i>vector, list, deque</i>) skirstant studentus į pažangius ir nepažangius.  </p>

<h4><b> Strategijų aprašymai: </b> </h4>
<ol>
    <li> Bendro studentų konteinerio (<i>vector, list ir deque tipų</i>) skaidymas (rūšiavimas) į du naujus <b>to paties tipo</b> konteinerius: pažangius ir nepažangius.</li>
    <li> Bendro studentų konteinerio (<i>vector, list ir deque</i>) skaidymas (rūšiavimas) panaudojant tik nepažangių mokinių konteinerį. Tokiu būdu, jei studentas yra nepažangus, jis įkeliamas į nepažangiųjų konteinerį ir ištrinamas iš bendro studentų konteinerio. Atminties atveju ši strategija - efektyvesnė, tačiau dažni trynimai gali būti neefektyvūs tam tikro tipo konteineriams.</li>
    <li>Bendro studentų konteinerio (<i>vector, list ir deque</i>) skaidymas (rūšiavimas) optimizuojant antrąją strategiją naudojant Standard Template Library (STL)</li>
</ol>

<p>Strategijų laiko tyrimų rezultatai pateikti žemiau. </p>

<h2>Naudojimosi instrukcija</h2>
<ol>
    <li>Susiinstaliuoti <a href="https://gnuwin32.sourceforge.net/packages/make.htm">MAKE</a></li>
    <li>Atsidaryti terminalą</li>
    <li>Klonuoti programos repozitoriją</li>

    git clone https://github.com/augustetum/objektinis_programavimas_1.git

 <li>Terminale rašyti žemiau esančią komandą, norint paleisti konteinerių tyrimą
 <pre><code>make runT</code></pre>
 Terminale rašyti žemiau esančią komandą, norint paleisti 1 strategiją
 <pre><code>make run1</code></pre></li>
 Terminale rašyti žemiau esančią komandą, norint paleisti 2 strategiją
 <pre><code>make run2</code></pre></li>
  Terminale rašyti žemiau esančią komandą, norint paleisti 3 strategiją
 <pre><code>make run3</code></pre></li>
   Terminale rašyti žemiau esančią komandą, norint paleisti pradinę programą
 <pre><code>make runP</code></pre></li>
</ol>

<h2>Tyrim rezultatai</h2>

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


<h2>2 Strategija | Tyrimo rezultatai </h2>
<p> Įvykdytos trys iteracijos, visose iteracijose pasirinktas rikiavimas pagal galutinį balą su vidurkiu</p>

| Studentų kiekis faile | Konteinerio tipas | Programos veikimo laikas |
| --------------------- | ------------------ | ------------ |
| 1000 | Vektoriai (vectors) | 0.020274s |
| 1000 | Dvipusė eilė (deque) | 0.00809744s |
| 1000 | Sąrašai (list) | 0.00756467s |
| |
| 10 000 | Vektoriai (vectors) | 0.0565011s |
| 10 000 | Dvipusė eilė (deque) | 0.0453732s |
| 10 000 | Sąrašai (list) | 0.0445289s |
| |
| 100 000 | Vektoriai (vectors) | 0.507529s |
| 100 000 | Dvipusė eilė (deque) | 0.483269s |
| 100 000 | Sąrašai (list) | 0.514169s |
| |
| 1 000 000 | Vektoriai (vectors) | 2.38923s |
| 1 000 000 | Dvipusė eilė (deque) | 2.50562s |
| 1 000 000 | Sąrašai (list) | 3.43698s |
| |
| 10 000 000 | Vektoriai (vectors) | 69.5301s |
| 10 000 000 | Dvipusė eilė (deque) | 68.4052s |
| 10 000 000 | Sąrašai (list) | 88.9485s |


<h2>3 Strategija | Tyrimo rezultatai  </h2>
<p> Įvykdytos trys iteracijos, visose iteracijose pasirinktas rikiavimas pagal galutinį balą su vidurkiu</p>

| Studentų kiekis faile | Konteinerio tipas | Programos veikimo laikas |
| --------------------- |  ------------ | -------- |
| 1000 | Vektoriai (vectors) | 0.00832676s |
| 1000 | Dvipusė eilė (deque) | 0.00677876s |
| 1000 | Sąrašai (list) | 0.00626292s |
| |
| 10 000 | Vektoriai (vectors) | 0.0471794s |
| 10 000 | Dvipusė eilė (deque) | 0.0363412s |
| 10 000 | Sąrašai (list) | 0.0351442s |
| |
| 100 000 | Vektoriai (vectors) | 0.418547s |
| 100 000 | Dvipusė eilė (deque) | 0.398046s |
| 100 000 | Sąrašai (list) | 0.411272s |
| |
| 1 000 000 | Vektoriai (vectors) | 1.70978s |
| 1 000 000 | Dvipusė eilė (deque) | 1.73145s |
| 1 000 000 | Sąrašai (list) | 2.06093s |
| |
| 10 000 000 | Vektoriai (vectors) | 59.2562s |
| 10 000 000 | Dvipusė eilė (deque) | 58.4033s |
| 10 000 000 | Sąrašai (list) | 62.6438s |
