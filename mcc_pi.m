% 1.1 Funkcijska datoteka
function [tockekrog,tockekvadrat] = mcc_pi(tocke)
    tockekvadrat = (rand(2,tocke)-0.5)*2;
    tockekrog = [];
    
    for t = 1:tocke
        razdalja = sqrt(tockekvadrat(1,t)^2+tockekvadrat(2,t)^2);
        if razdalja <= 1
            tockekrog = [tockekrog [tockekvadrat(1,t); tockekvadrat(2,t)]];
        end
    end
end
