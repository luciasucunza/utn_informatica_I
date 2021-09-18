float pasaje_promedio (int viajes_realizados,float, *tarifa, int *viajes, int tarifa_cant );

float pasaje_promedio (int viajes_realizados,float, *tarifa, int *viajes, int tarifa_cant )
{
  int i, gastos, viajesaux;
  
  gastos = 0;
  viajesaux = viajes_realizados;
  for( i = 0 ; i < tarifa_cant ; i++ )
  {
    if( viajesaux >= viajes[i] )
    {
      viajesaux = viajesaux - viajes[i];
      gastos = gastos + viajes[i] * tarifa[i];
    }
    else
    {
      viajesaux = viajes[i] - viajesaux;
      gastos = gastos + viajesaux * tarifa[i];
      viajesaux = 0;
      break;      
    }
  }
  if( viajesaux > 0 )
    return 0;
  return ( gastos/viajes_realizados );
}