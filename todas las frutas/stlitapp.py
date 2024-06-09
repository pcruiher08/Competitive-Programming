import streamlit as st
import plotly.graph_objects as go
import numpy as np
from datetime import datetime

def investment_growth_over_time_custom(principal, firstRate, secondRate, totalDays):
    time_points = np.arange(0, totalDays + 1, 1)
    calc = principal

    firstRateDays = (datetime(2024, 4, 15) - datetime.now()).days
    secondRateDays = totalDays - firstRateDays

    delta = [0]
    values = [0]
    for i in range(totalDays + 1):
        if i < firstRateDays:
            calc += calc * firstRate / 100 / 365
        else:
            calc += calc * secondRate / 100 / 365
            
        values.append(calc - principal)
        if i > 0:
            delta.append(values[i] - values[i - 1])

    return time_points, delta

st.title('Nu')

# User inputs
firstRate = st.sidebar.number_input('First Rate (%)', value=15)
secondRate = st.sidebar.number_input('Second Rate (%)', value=14)
initial_investment = st.sidebar.number_input('Initial Investment (MXN)', value=300000)
totalDays = st.sidebar.number_input('Total Days', value=10)

initial_investments = [initial_investment]
initial_investments = sorted(initial_investments)[::-1]

results = []
for principal in initial_investments:
    time_points, values = investment_growth_over_time_custom(principal, firstRate, secondRate, totalDays)
    results.append([list(time_points), [values, principal]])

fig = go.Figure()

for days, values in results:
    area = np.trapz(values[0], days)

    red_value = np.random.randint(0, 256)
    green_value = np.random.randint(0, 256)
    blue_value = np.random.randint(0, 256)
    transparency = '0.5'
    line_color = f'rgba({red_value}, {green_value}, {blue_value}, {transparency})'

    fig.add_trace(go.Scatter(
        x=days + days[::-1],
        y=values[0] + [0] * len(values[0]),
        fill='toself',
        fillcolor=f'rgba({red_value}, {green_value}, {blue_value}, {0.3})',
        mode='none',
        showlegend=False
    ))

    fig.add_trace(go.Scatter(
        x=days,
        y=values[0],
        mode='lines',
        name=f'Inversión: {values[1]} MXN / Primer día: {round(values[0][1], 2)} MXN / Ganancia: {area:.2f} MXN',
        line=dict(color=f'rgba({red_value}, {green_value}, {blue_value}, {0.9})')
    ))

fig.update_layout(
    title='Análisis Cajita de ahorro Nu',
    xaxis_title='Días',
    yaxis_title='Rendimiento (MXN)',
    paper_bgcolor='rgba(0,0,0,0)',
    plot_bgcolor='rgba(0,0,0,0)',
    font=dict(color='white'),
)

st.plotly_chart(fig)
