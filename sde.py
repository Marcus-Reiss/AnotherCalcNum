# An algorithm to solve second degree equations (with Baskhara's formula)

def treat_eq():
    eq = str(input('Write the function (in x) you want to equals zero >> ')).strip().replace(' ','')
    sig = '+-'
    if sig[0] in eq:
        eq = eq.replace(sig[0], ' ')
    if sig[1] in eq:
        eq = eq.replace(sig[1], ' -')    
    div = eq.split()    
    coeff(div)

def coeff(div):
    ft = ['*x^1','x^1','*x','x']
    isb = False
    for term in div:
        if '^2' in term:
            if '*' in term:
                a = float(term.replace('*x^2',''))
            else:
                a = float(term.replace('x^2',''))
        else:
            for t in ft:
                if t in term:
                    b = float(term.replace(t,''))
                    isb = True
                    break
            if not isb:
                c = float(term)
                isb = False            
    print(f'{a} , {b} , {c} ')

treat_eq()
