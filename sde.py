# An algorithm to solve second degree equations (with Baskhara's formula)
from cmath import sqrt

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
    isb = lin = cte = False    
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
                    isb = lin = True
                    break
            if not isb:
                c = float(term)
                cte = True
            isb = False            
    if not lin:
        b = 0
    if not cte:
        c = 0
    print(f'Solving the equation:\033[32m {a}x^2 + ({b})x + ({c}) = 0\033[m')
    baskhara(a, b, c)

def baskhara (a = 0, b = 0, c = 0):
    x1 = (-b + sqrt(b**2 - 4*a*c))/(2*a)
    x2 = (-b - sqrt(b**2 - 4*a*c))/(2*a)
    print('\033[34mRoots: \033[36m {} , {}\033[m'.format(x1,x2))

treat_eq()
