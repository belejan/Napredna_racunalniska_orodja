% 1.2 Programska datoteka

% 1.3 Anonimna funkcija

stevilo_tock = 1000;
kroznica_tocke = @(i) [cos(linspace(0, 2*pi, i)); sin(linspace(0, 2*pi, i))];
tocke_krog = kroznica_tocke(stevilo_tock);

% 1.4 Vizualizacija

[krog, kvadrat] = mcc_pi(stevilo_tock);
area_pi(krog, kvadrat)

plot(tocke_krog(1,:), tocke_krog(2,:), "red."); % Naredimo kroznico
hold on
plot(kvadrat(1,:), kvadrat(2,:),"blue."); % Tocke samo v kvadratu
hold on
plot(krog(1,:), krog(2,:),"black*"); % Tocke v krogu

% 1.4.1 Legenda grafa
legend('Krožnica','Točke izven kroga','Točke v krogu')
title('Metoda Monte Carlo za iskanje približka števila pi')
xlabel('x')
ylabel('y')
hold off

% Funkcija, ki primerja stevilo tock znotraj in zunaj krog (+napaka PI)

function[stevilo_pi, napaka_pi] = area_pi(tockekrog,tockekvadrat)

    stevilo_pi = (length(tockekrog)/length(tockekvadrat))*4;
    napaka_pi = pi - stevilo_pi;
end
